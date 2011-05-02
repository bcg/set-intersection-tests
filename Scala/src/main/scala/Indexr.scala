import gnu.trove.set.TIntSet
import gnu.trove.set.hash.TIntHashSet


object Indexr extends Application {

  val n = 10000000
  val one = new TIntHashSet(n)
  val two = new TIntHashSet(n)
  var i = 0

  var t = System.currentTimeMillis

  i = 0
  while(i <= n) {
    one.add(i)
    i += 1
  }

  Console.println("Loaded set in " + ((System.currentTimeMillis-t)/ 1000.0))

  t = System.currentTimeMillis

  i = 0
  while(i <= n) {
    two.add(i)
    i += 1
  }

  Console.println("Loaded set in " + ((System.currentTimeMillis-t)/ 1000.0))

  t = System.currentTimeMillis

  two.retainAll(one)

  Console.println(two.size() + " intersects in " + ((System.currentTimeMillis-t)/ 1000.0));
}

