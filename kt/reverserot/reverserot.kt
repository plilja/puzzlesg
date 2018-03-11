import java.util.*

const val ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."

private tailrec fun run(input: Scanner) {
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
