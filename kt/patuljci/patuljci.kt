fun main(args: Array<String>) {
    val ints = ArrayList<Int>()
    for (i in 1..9) {
        ints.add(Integer.parseInt(readLine()))
    }
    val totalSum = ints.sum()
    outer@ for (i in 0 until 9) {
        for (j in i + 1 until 9) {
            if (totalSum - ints[i] - ints[j] == 100) {
                for (k in 0 until 9) {
                    if (k != i && k != j) {
                        println(ints[k])
                    }
                }
                break@outer
            }
        }
    }
}


