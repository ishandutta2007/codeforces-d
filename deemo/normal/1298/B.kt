private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double

private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of long
private fun readDoubles() = readStrings().map { it.toDouble() } // list of double

private val OL = mutableListOf<String>()
private fun addOL(s: String){
    OL.add(s)
}
private fun outputRes() {
    println(OL.joinToString("\n"))
}

private val MAXN = 1e5.toInt()
private val MOD = 1e9.toInt() + 7

fun main() {
    val n = readInt()
    val a = readInts()
    val res = mutableListOf<Int>()
    for (i in 0 until n) {
        var found = false
        for (j in i + 1 until n) {
            found = found || a[i] == a[j]
        }
        if (!found)
            res.add(a[i])
    }
    println(res.size)
    println(res.joinToString(" "))
}