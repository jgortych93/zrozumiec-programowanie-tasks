

firstString = "This is first string"
secondString = "And this is second string"

print("First string id: " + str(id(firstString)))

print("Second string id: " + str(id(secondString)))

firstString = "Change the string"

print("First string after change: " + str(id(firstString)))

secondString += "Append something"
print("Second string after append operation: " + str(id(secondString)))

firstString.lower()
print("First string after lower() calling: " + str(id(firstString)))

secondString.split(' ')
print("Second string after split operation: " + str(id(secondString)))
