var set = require ('./set').set

var one = set(1),
    two = set(1);

var t1 = new Date();

for (i=0;i<=9999999;i=i+1) {
  one.add(i);
}
console.log(one.size() + ' inserted in ' + Math.floor((new Date() - t1) / 1000));

for (i=0;i<=9999999;i=i+1) {
  two.add(i);
}

t1 = new Date();

var matches = one.intersectionCount(two);

console.log(matches + ' matched in ' + Math.floor((new Date() - t1) / 1000));

