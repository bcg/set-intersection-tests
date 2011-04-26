exports.set = function () {
  var members = {}
    , eachArgument = function (args, fn) { Array.prototype.slice.apply(args).forEach (fn) }
    , set = function (item) { return members.hasOwnProperty (item) }

  set.has = set
  
  set.union = function (other) {
    var union = exports.set.apply ({}, set.members)
    union.add.apply (set, other.members)
    return union }
  
  set.intersection = function (other) {
    var intersection = exports.set ()
    set.members.forEach (function (elt) {
      if (other (elt)) intersection.add (elt) })
    return intersection }

  set.intersectionCount = function (other) {
    var intersection = 0;
    set.members.forEach (function (elt) {
      if (other (elt)) intersection++; })
    return intersection }

  set.add = function () {
    eachArgument (arguments, function (arg) { members [arg] = true }) }

  set.add.apply (set, arguments)

  set.del = function (item) {
    eachArgument (arguments, function (arg) { delete members [arg] }) }

  set.__defineGetter__ ('members', function () {
    var m = []
    for (k in members) if (members.hasOwnProperty (k)) m.push (k)
    return m })
  
  delete set.size
  set.size = function () {return set.members.length}

  set.toString = function () { return "<Set:" + set.members.join (",") + ">" }

  return set
}

