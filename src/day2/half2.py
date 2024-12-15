safe_registers = 0

exceeded = False
inverted = False

increasing = False
decreasing = False

def safe_register(register):
    pass

with open("adventOfCode2024/inputs/day2.txt", 'r') as file:
    for line in file:

        increasing = False
        decreasing = False

        exceeded = False
        inverted = False

        if line != None:
            register = line.split(' ')
            
            for i in range(len(register)):
                register[i] = int(register[i])
            
            for i in range(len(register) - 1):

                if register[i] > register[i + 1]:
                    decreasing = True

                if register[i] < register[i + 1]:
                    increasing = True
                    
                difference = abs(register[i] - register[i + 1])
                if difference == 0 or difference > 3:
                    exceeded = True

            safe_register(register)
            
            if decreasing != increasing and decreasing != increasing and not exceeded:
                safe_registers += 1

print(safe_registers)