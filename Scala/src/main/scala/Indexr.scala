//import scala.collection.mutable.Set
import gnu.trove.set.TIntSet
import gnu.trove.set.hash.TIntHashSet


object Indexr extends Application {

  val one = new TIntHashSet(100000);
  val two = new TIntHashSet(100000);

  var t = System.currentTimeMillis

  for (i <- 0.until(99999)) {
    one.add(i)
  }

  Console.println("Loaded set in " + ((System.currentTimeMillis-t)/ 1000.0))

  t = System.currentTimeMillis

  for (i <- 0.until(99999)) {
    two.add(i)
  }

  Console.println("Loaded set in " + ((System.currentTimeMillis-t)/ 1000.0))

  t = System.currentTimeMillis

  two.retainAll(one)

  Console.println(two.size() + " intersects in " + ((System.currentTimeMillis-t)/ 1000.0));
}

