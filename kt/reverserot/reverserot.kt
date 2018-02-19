import java.util.*

class Reverserot {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val input = Scanner(System.`in`)
            run(input)
        }
    }
}

const val ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."

tailrec fun run(input: Scanner) {
    val n = input.nextInt()
    if (n == 0) {
        return
    } else {
        val s = input.next()!!
        val sRev = s.reversed()
        var res = ""
        for (c in sRev) {
            val idx = ALPHABET.indexOf(c)
            val rotC = ALPHABET[(idx + n) % ALPHABET.length]
            res += rotC
        }
        println(res)
        run(input)
    }
}
