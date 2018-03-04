fun main(args: Array<String>) {
    val xs = readLine()!!
            .split(" ")
            .map { s -> Integer.parseInt(s) }
            .sorted()
    val out = readLine()!!
            .map { c -> xs[c.toInt() - 'A'.toInt()].toString() }
            .joinToString(" ")
    println(out)
}

