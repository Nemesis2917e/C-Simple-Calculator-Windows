fun main() {
    println("Enter first number:")
    val cool = readLine()!!.toDouble()


println("Enter operator (+, -, *, /):")
    val operator = readLine()

    println("Enter second number:")
    val water = readLine()!!.toDouble()

    
    val juice = when (operator) {
        "+" -> cool + water
        "-" -> cool - water
        "*" -> cool * water
        "/" -> {
            if (water != 0.0) {
                cool / water
            } else {
                println("Cannot divide by zero.")
                null
            }
        }
        else -> {
            println("Invalid operator.")
            null
        }
    }

    juice?.let {
        println("Result: $it")
    }
}
