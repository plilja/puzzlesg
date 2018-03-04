class Aboveaverage {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val c = readLine()!!.toInt()
            repeat(c, { _ ->
                val grades = readLine()!!
                        .split(' ')
                        .map { it.toInt() }
                        .drop(1)
                val average = grades.average()
                val aboveAverage = grades
                        .filter { it > average }
                        .size
                val percentage = 100 * aboveAverage / grades.size.toDouble()
                println("%.3f%%".format(percentage))
            })
        }
    }
}
