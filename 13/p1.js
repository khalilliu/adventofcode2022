const fs = require('fs')

function readInput(isTest) {
  const inputFile = isTest ? './input_test': 'input'   
  return fs.readFileSync(inputFile).toString()
        .split(/\n\n/)
        .map(arr => arr.split(/\n/))
        .map(arr => arr.map(v => JSON.parse(v)))
}

function dfs(a, b) {
  if(Number.isInteger(a) && Number.isInteger(b)) {  
    if(a < b) return -1;
    else if(a == b) return 0;
    else if(a > b) return 1;
  }
  if(typeof a === 'undefined' && typeof b === 'undefined') return 0;
  else if(typeof a === 'undefined') return -1;
  else if(typeof b === 'undefined') return 1;
  let arr1 = a, arr2 = b;
  if(!Array.isArray(a)) arr1 = [a]
  if(!Array.isArray(b)) arr2 = [b]

  for(let i=0; i<Math.max(arr1.length, arr2.length); i++) {
    let t = dfs(arr1[i], arr2[i])
    if(t != 0) {
      return t;
    }
  }
  return 0;
}

function main() {
  const isTest = process.argv.includes('--test')
  const input = readInput(isTest)

  let res = 0;

  for(let i=0; i<input.length; i++) {
    if(dfs(input[i][0], input[i][1]) == -1) res += i + 1;
  }

  console.log(res);
}

main()


