class TwoStones {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val n = Integer.parseInt(readLine())
            if (n % 2 == 0) {
                println("Bob")
            } else {
                println("Alice")
            }
        }
    }
}
