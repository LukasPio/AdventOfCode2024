import java.io.File
import kotlin.math.abs

fun main(args: Array<String>) {
    val input = File("src/inputs/day1.txt").readLines()

    val leftIds = input.map { it.split("   ")[0].toInt() }.toMutableList()
    val rightIds = input.map { it.split("   ")[1].toInt() }.toMutableList()

    var totalSum = 0

    while (leftIds.isNotEmpty() && rightIds.isNotEmpty()) {
        val minOfLeft = leftIds.minOrNull()!!
        val minOfRight = rightIds.minOrNull()!!

        totalSum += abs(minOfLeft - minOfRight)

        leftIds.remove(minOfLeft)
        rightIds.remove(minOfRight)
    }

    println("Result: $totalSum")
}