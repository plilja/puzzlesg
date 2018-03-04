import java.lang.Integer.signum

class Quadrant {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val x = Integer.parseInt(readLine()!!)
            val y = Integer.parseInt(readLine()!!)
            val r = when (Pair(signum(x), signum(y))) {
                Pair(1, 1) -> 1
                Pair(-1, 1) -> 2
                Pair(-1, -1) -> 3
                else -> 4
            }
            println(r)
        }
    }
}
