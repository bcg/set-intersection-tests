package sbt

class Indexr(info: ProjectInfo) extends DefaultProject(info) {
    override def fork = Some(new ForkScalaRun {
        override def runJVMOptions = super.runJVMOptions ++ Seq("-Xmx1024m")
        override def scalaJars = Seq(buildLibraryJar.asFile, buildCompilerJar.asFile)
    })
}

