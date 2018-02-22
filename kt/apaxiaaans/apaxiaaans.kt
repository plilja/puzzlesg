class Apaxiaaans {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val s = readLine()!!
            var r = ""
            var pre = '?'
            for (c in s) {
                if (c != pre) {
                    r += c
                    pre = c
                }
            }
            println(r)
        }
    }
}
