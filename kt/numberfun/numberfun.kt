import java.util.*

class Numberfun {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val input = Scanner(System.`in`)
            run(input)
        }
    }
}

private fun run(scanner: Scanner) {
    val n = scanner.nextInt()
    for (i in 1..n) {
        val a = scanner.nextInt()
        val b = scanner.nextInt()
        val c = scanner.nextInt()
        val operators = listOf<(Int, Int, Int) -> Boolean>(
                { x, y, z -> x + y == z },
                { x, y, z -> x - y == z },
                { x, y, z -> x * y == z },
                { x, y, z -> x % y == 0 && x / y == z }
        )
        val res = operators.flatMap { op -> listOf(op(a, b, c), op(b, a, c)) }
                .reduce { x, y -> x || y }
        if (res) {
            println("Possible")
        } else {
            println("Impossible")
        }
    }
}
