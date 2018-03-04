import java.lang.Math.pow

class Pizza2 {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val (r, c) = readLine()!!
                    .split(" ")
                    .map { s -> Integer.parseInt(s).toDouble() }
                    .toList()
            val pizzaArea = pow(r, 2.0) * Math.PI;
            val cheeseArea = pow(r - c, 2.0) * Math.PI;
            val percentage = 100 * cheeseArea / pizzaArea;
            println("%.6f".format(percentage))
        }
    }
}
