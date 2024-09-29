# Angara
## IoT and Embedded-focused language

###	Lightweight and Efficient: 
Focused on performance and memory efficiency for resource-constrained IoT devices.
###	C-inspired Syntax: 
Incorporates some of C’s strengths while introducing more modern and readable syntax.
###	Power Management: 
Syntax and features designed for low-power and energy-saving modes, important for IoT systems.
###	Concurrency and Event Handling: 
Built-in abstractions for managing real-time events and handling concurrency in IoT devices.
###	Networking and Communication: 
Simplified integration for IoT communication protocols (e.g., MQTT, CoAP, BLE).
###	Memory Management: 
Combines manual and automatic memory management, giving developers control while keeping things safe.

## Function Definition Syntax

### Basic function:
```
function <name>(arguments) returns <data type> { body }
```

### Function with error handling:
```
function <name>(arguments) returns <data type> | throws <error type> { body }
```

## Core Language Features

### Power Management: 
Includes built-in features for handling low-power states, e.g.
```
power_save { sleep_until_interrupt(); }
```
###	Concurrency Abstractions: 
Simplified syntax for event handling or concurrent tasks, e.g.
```
task sensor_task { 
    loop { 
        read_sensor(); 
        delay(1000); 
    }
}
```
### Direct Hardware Access: 
Easy access to hardware registers with readable syntax, e.g.
```
register PWM_CONTROL at 0x4001_0000; PWM_CONTROL.set_bits(ENABLE | MODE_FAST);
```
###	Built-in Networking and Communication:
Abstractions for common IoT communication protocols, e.g.
```
define connection = mqtt::connect("broker.hivemq.com");
connection.publish("sensor/data", temperature_data);.
```
###	Memory Management:
Supports both manual and automatic memory management, e.g.
```
let buffer: [u8; 256] = allocate(); and let data = new DataStruct();.
```

## Syntax for Attaching Libraries/Modules

Use the attach keyword to include external libraries or modules:
```
attach device::temperature_sensor; attach network::mqtt;
```

## Syntax for Variable Creation

Use define to create variables:
```
define temperature = 25;
```

## Data types:

Integer Data Types for Angara:

	int8: 8-bit signed integer.
	int16: 16-bit signed integer.
	int32: 32-bit signed integer.
	int64: 64-bit signed integer.

Floating-Point Data Types for Angara:

	float: Represents a single-precision (32-bit) floating-point number, 
            suitable for most calculations with moderate precision.
	double: Represents a double-precision (64-bit) floating-point number,
            providing greater precision for calculations that require it.

Character and String Data Types for Angara:

	char: Represents a single character,
    useful for individual letters, digits, or symbols.
	string: Represents a sequence of characters, 
    ideal for text and messages.

## Struct Definition in Angara

```
struct <StructName> {
    field1: dataType1,
    field2: dataType2,
    // Add more fields as needed
}
```

### Creating and Using Structs:

You can create an instance of a struct and access its fields as follows:

```
define reading = SensorData(temperature: 25.0,
 humidity: 60.5, timestamp: "2024-09-28T12:00:00Z");

// Accessing struct fields
define temp = reading.temperature;
define hum = reading.humidity;
```

## File Extension: .ara

## Data passing and referencing:

When it comes to passing data into and out of functions, especially in the context of embedded systems and IoT, efficiency and control over memory usage are critical.

1. Pass by Value (Copy):

This is the default way to pass data where the function receives a copy of the argument. Changes to the argument inside the function don’t affect the original variable. It’s simple but can be inefficient for large data structures.

Use Case: When dealing with small, simple data types like integers or floats.

```
function add(a: int32, b: int32) returns int32 {
    return a + b;
}

define result = add(10, 20); // Pass by value
```

2. Pass by Reference (Pointer):

Instead of passing the actual data, we pass a reference (or pointer) to the data. This is more efficient for large data structures and allows the function to modify the original data. However, it introduces complexity, as you need to manage memory and ensure that references remain valid.

Use Case: When working with large data structures, structs, or arrays.

```
function modifyValue(ptr: *int32) {
    *ptr = *ptr + 10; // Dereference the pointer to modify the original value
}

define value = int32(5);
modifyValue(&value); // Pass by reference (pointer)
```

3. Pass by Reference (Non-Pointer):

Some languages allow you to pass by reference without explicit pointers. The function can modify the argument directly, but the syntax is cleaner since there’s no need to deal with pointers.

Use Case: When you want the function to modify the original data without the complexity of pointers.

```
function modifyValue(ref a: int32) {
    a = a + 10;
}

define value = int32(5);
modifyValue(value); // Pass by reference without using pointers
```

4. Return Multiple Values (Tuples or Structs):

Instead of using pointers to modify data, another option is to return multiple values from a function using tuples or structs. This can eliminate the need for pointers in some cases, while still enabling you to pass complex data in and out of functions.

Use Case: When you need to return multiple results from a function.

```
function getData() returns (int32, int32) {
    return (25, 60); // Returns temperature and humidity
}

define (temp, hum) = getData(); // Multiple value return
```

## Logic flow

1. If-Else Statement:

The if-else construct allows conditional branching based on boolean expressions.

```
if (condition) {
    // Code to execute if condition is true
} else if (another_condition) {
    // Code to execute if another_condition is true
} else {
    // Code to execute if no conditions are true
}
```

Example:

```
define temperature = int32(30);

if (temperature > 25) {
    print("It's hot.");
} else if (temperature < 15) {
    print("It's cold.");
} else {
    print("The temperature is moderate.");
}
```

2. Switch statement

The switch statement is used for selecting one of many code blocks to execute based on the value of an expression.
It’s particularly efficient for handling multiple discrete values, such as handling different device states or modes.

```
switch (expression) {
    case value1: {
        // Code for value1
        break;
    }
    case value2: {
        // Code for value2
        break;
    }
    default: {
        // Code if no cases match
    }
}
```

```
define mode = int32(1);

switch (mode) {
    case 0: {
        print("Device is off.");
        break;
    }
    case 1: {
        print("Device is in standby.");
        break;
    }
    case 2: {
        print("Device is active.");
        break;
    }
    default: {
        print("Unknown mode.");
    }
}
```

## Error Handling in Angara:

1. Throws in Function Signature

We can define functions that may throw an error by using a throws clause in the function signature, 
indicating the function might raise an error during execution.

```
function <name>(arguments) returns <returnType> | throws <ErrorType> { 
    // Body 
}
```

```
function readFile(filePath: string) returns string throws FileNotFoundError {
    // Code to read file
}
```

2. Try-Catch Block

The try-catch block will allow you to handle errors in a controlled manner, 
allowing the program to recover or respond appropriately to the error.

```
try {
    // Code that may throw an error
} catch (ErrorType) {
    // Handle the error
} finally {
    // (Optional) code that will always execute, for cleanup
}
```

```
try {
    define data = readFile("config.txt");
    print("File read successfully.");
} catch (FileNotFoundError) {
    print("Error: File not found.");
} catch (PermissionDeniedError) {
    print("Error: Permission denied.");
} finally {
    print("Execution completed.");
}
```

## Type Safety in Angara

1. Strong Typing:

In Angara, variables and function parameters must have explicitly declared types. 
This prevents inadvertent type mismatches, such as passing a string where an integer is expected. 
The type of a variable is checked at compile time to ensure correctness.

```
define <variableName> as <dataType> = <initialValue>;
```

```
define temp as int32 = 25;         // temp is defined as an int32
define greeting as string = "Hi!"; // greeting is defined as a string
```

2. Type Inference:

For simplicity, Angara includes limited type inference in certain cases where the type is obvious from context. 
However, explicit typing would still be the default to maintain clarity.

```
define temp = int32(25);  // Type inferred from int32 constructor
```

3. Function Signatures with Type Safety:

When defining functions, both the parameter types and return types must be specified.
The function will only accept arguments of the correct types and will guarantee that the correct type is returned.

```
function multiply(a as int32, b as int32) returns int32 {
    return a * b;
}
```

4. Type Conversion (Casting):

Sometimes, it’s necessary to convert between types. 
In Angara, explicit casting is required to convert a value from one type to another, preventing unintended implicit conversions.

```
define temp as int32 = 25;
define precise_temp as float = temp as float;  // Cast int32 to float
```

5. Type Errors:

If the wrong type is provided or if an operation is attempted on incompatible types, 
Angara will provide clear error messages during compilation, pointing to the exact place where the issue occurs.

```
define temperature as float = 25.5;
define mode as int32 = 2;

if (temperature == mode) {
    // Error: Comparison between float and int32 is not allowed
}
```


