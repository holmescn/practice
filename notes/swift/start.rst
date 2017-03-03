=============
  Swift 学习
=============

-------------
    简介
-------------

注册并开始了在 `teamtreehouse.com` 上的课程。开始系统的学习 iOS, Android 等系统上的 native
编程。这个网站的视屏非常丰富，而且包含了很多想学习的东西。价格是 $25 一个月。

------------
Swift basics
------------

 What is Swift
----------------

基础介绍，什么是程序，什么是语法（syntax），介绍了如何学习。

    XCode
----------------

介绍了如何安装 XCode，以及创建了一个 Playground。

Variables & Constants
----------------------

基础。

Syntax
    语法和关键词的集合。

.. code::
    // This is a variable
    // The type of the variable is inferred to String
    var str = "Hello, World."

    // This is a constant
    let cStr = "Hello, Constants."

    // explicit type declare
    var str2 : String = "Hello, String"

---------
  Types
---------

Printing Results
----------------

.. code::
    // only accept one parameter
    print("This is a single print ")
    print("continue the above line.")

    // print and give a new line
    println("I will take a line.")

    // embed variable or constant into a string
    var str = "str1"
    let const = "constant"
    println("\(str) \(const)")

Strings
-------

演示了 `\n`, `\t` 和 Emoji

Numbers and Booleans
--------------------

.. code::
    let year = 10 // Int or Integer
    let version = 1.0 // Double, 15 decimal digits
    let minor: Float = 0.1 // Float, 7 decimal digits
    let isAwesome = true // Bool, true or false

---------
Operators
---------

介绍了基本的操作符:

.. code::
    let a = 1 + 2
    let b = 3 - 1
    let c = a * b
    let d = b / a
    let e = b % a

    // ++
    // --
    // -
    let f = 0
    f ++
    ++ f
    f --
    -- f

    // ! Not
    let on = true
    let off = ! no

还讲解了运算符的优先级……

-----------
Collections
-----------

Array
-----

.. code::
    let todo = ["Learn Swift", "Build App", "Deploy App"]
    println(todo.count)
    todo += ["Debug App", "Fix Bugs"]
    todo.removeAtIndex(2)
    todo.insert("Learn iOS", atIndex: 1)

Dictionary
----------

.. code::
    let currencies = ["US":"Dollar", "UK":"Pound", "JP":"Yen"]
    let ukCurrency = currencies["UK"]

------------
Control Flow
------------

Loops
-----

.. code::
    let todo = ["Learn Swift", "Build App", "Deploy App"]
    for item in todo {
        println(item)
    }

    // print 1, 2, 3
    for num in 1...3 {
        println(num)
    }

    // print 1, 2, 3
    for num in 1..<4 {
        println(num)
    }

    for var i = 0; i < todo.count; i++ {
        println(todo[i])
    }

    while somethingTrue {
        // doing something somethingTrue become false.
    }

If Statement
------------

.. code::
    if condition {
        // Do something
    } else if condition2 {
        // Do something
    } else {
        // Do something
    }

Switch Statement
----------------

.. code::
    for card in 1...13 {
        switch card {
        case 1:
            println("Ace")
        case 11:
            println("Jack")
        case 12:
            println("Queen")
        case 13:
            println("King")
        default:
            println("\(card)")
        }
    }

    let card = 10
    switch card {
    case 11...13:
        println("Range match.")
    default:
        println("Don't forget this.")
    }

--------------------
Functions & Optional
--------------------

Function
---------

.. code::
    func aSimpleFunc() {
        // This is a function that do not need any parameter and do not return any value.
    }

    func functionWithParam(param1: Int, param2: String) {
        // a function that need two parameters, the first is an Integer, the section is
        // a string. It does not return any value.
    }

    func isEmployee(name: String) -> Bool {
        return false
    }

Named Parameters
----------------

.. code::
    // first "height" is the parameter label, could be any variable name.
    // second "height" is the local variable name.
    func calculateArea(height height: Int, width width: Int) -> Int {
        return height * width
    }

    // this is a short syntax for the label and local variable name are the same.
    func calculateArea(#height: Int, #width: Int) -> Int {
        return height * width
    }


Tuple
-----

.. code::
    let aTuple = (1, "String")
    let p1 = aTuble.0
    let p2 = aTuble.1
    let (p3, p4) = aTuple
    let (_,  p5) = aTuple
    let (p6, _) = aTuple

    // named tuple
    func greeting(person: String) -> (greeting: String, language: String)) {
        return ("Hello \(person)", "english")
    }
    let result = greeting("Tom")
    println("\(result.language)")


