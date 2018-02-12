class Skener {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val (r, c, zr, zc) = readLine()!!.split(" ").map { s -> Integer.parseInt(s) }.toList()
            val input = ArrayList<String>()
            for (i in 0 until r) {
                val line = readLine()
                input.add(line!!)
            }
            for (i in 0 until r) {
                for (rep1 in 0 until zr) {
                    val sb = StringBuilder()
                    for (j in 0 until c) {
                        val ch = input[i][j]
                        for (rep2 in 0 until zc) {
                            sb.append(ch)
                        }
                    }
                    println(sb)
                }
            }
        }
    }
}

