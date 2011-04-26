import scala.collection.mutable.Set

object Indexr extends Application {

  var one = Set(1)
  var two = Set(1)

  var t = System.currentTimeMillis

  for (i <- 0.until(9999999)) {
    one += i
  }

  Console.println("Loaded set in " + ((System.currentTimeMillis-t)/ 1000.0))

  t = System.currentTimeMillis

  two = one.clone

  Console.println("Loaded set in " + ((System.currentTimeMillis-t)/ 1000.0))

  t = System.currentTimeMillis
  val intersects = one intersect two

  Console.println(intersects.size + " intersects in " + ((System.currentTimeMillis-t)/ 1000.0));
}

