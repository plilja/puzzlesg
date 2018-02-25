import java.lang.Integer.max

class Filip {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val (a, b) = readLine()!!.split(" ")
            val a_ = Integer.parseInt(a.reversed())
            val b_ = Integer.parseInt(b.reversed())
            println(max(a_, b_))
        }
    }
}
