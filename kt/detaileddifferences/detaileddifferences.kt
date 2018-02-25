class Detaileddifferences {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val n = Integer.parseInt(readLine())
            for (i in 1..n) {
                val a = readLine()!!
                val b = readLine()!!
                val ss = StringBuilder()
                for (j in 0 until a.length) {
                    if (a[j] == b[j]) {
                        ss.append('.')
                    } else {
                        ss.append('*')
                    }
                }
                println(a)
                println(b)
                println(ss)
                println()
            }
        }
    }
}


