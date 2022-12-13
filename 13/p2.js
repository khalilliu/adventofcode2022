const fs = require('fs')

function readInput(isTest) {
  const inputFile = isTest ? './input_test': 'input'   
  return fs.readFileSync(inputFile).toString()
        .split(/\n\n/)
        .map(arr => arr.split(/\n/))
        .map(arr => arr.map(v => JSON.parse(v)))
}

function isUndefined(a) {
  return typeof a === 'undefined'
}

function dfs(a, b) {
  if(Number.isInteger(a) && Number.isInteger(b)) {  
    if(a < b) return -1;
    else if(a == b) return 0;
    else if(a > b) return 1;
  }

  if(isUndefined(a) && isUndefined(b)) return 0;
  else if(isUndefined(a)) return -1;
  else if(isUndefined(b)) return 1;
  
  let arr1 = a, arr2 = b;
  if(!Array.isArray(a)) arr1 = [a]
  if(!Array.isArray(b)) arr2 = [b]

  for(let i=0; i<Math.max(arr1.length, arr2.length); i++) {
    let t = dfs(arr1[i], arr2[i])
    if(t !== 0) {
      return t;
    }
  }
  return 0;
}

function main() {
  const isTest = process.argv.includes('--test')
  const input = readInput(isTest).flatMap(a => a)
  let A = [[2]], B = [[6]]  
  input.push(A, B)

  input.sort((a, b) => dfs(a, b))

  let res = 1;
  for(let i=0; i<input.length; i++) {
    if(JSON.stringify(input[i]) == JSON.stringify(A)) res *= i+1;
    if(JSON.stringify(input[i]) == JSON.stringify(B)) res *= i+1;
  }
  console.log(res)
}

main()


