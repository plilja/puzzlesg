import java.util.*

fun main(args: Array<String>) {
    val input = Scanner(System.`in`)
    val n = input.nextInt()
    for (i in 1..n) {
        val a = input.nextInt()
        val b = input.nextInt()
        val c = input.nextInt()
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

