def process_instructions(instructions, grid_size):
    # defining directions and their axes
    define_direction = {'E': (1, 0), 'W': (-1, 0), 'N': (0, 1), 'S': (0, -1)}
    # determining the initial position of the rover
    initial_x = 0
    initial_y = 0
    # defining the initial direction
    initial_direction = 'N'
    # to iterate all the character
    for MY_instruction in instructions:
        # condition for rovers movement
        # if the command is F the rover will move one step forward
        if MY_instruction == 'F':
            x, y = define_direction[initial_direction]
            new_x, new_y = initial_x + x, initial_y + y
            if 0 <= new_x < grid_size[0] and 0 <= new_y < grid_size[1]:  # checking if the position is valid or not
                initial_x, initial_y = new_x, new_y
        # ekhne clockwise rotation hbe
        elif MY_instruction == 'L':
            if initial_direction == 'N':
                initial_direction = 'W'
            elif initial_direction == 'W':
                initial_direction = 'S'
            elif initial_direction == 'S':
                initial_direction = 'E'
            else:
                initial_direction = 'N'
        # anti-clockwise hobe
        elif MY_instruction == 'R':
            if initial_direction == 'N':
                initial_direction = 'E'
            elif initial_direction == 'E':
                initial_direction = 'S'
            elif initial_direction == 'S':
                initial_direction = 'W'
            else:
                initial_direction = 'N'
    return initial_x, initial_y, initial_direction


instructions = input()
num_row = int(input())
num_col = int(input())
grid_size = (num_row, num_col)
result = process_instructions(instructions, grid_size)
print(result)
