from agent_two_rooms import Agent

class VaccumAgent1 (Agent):
    def __init__(self):
        pass  # Initialize the agent

    def sense(self, envn):
        self.environment = envn  # Store the environment the agent senses

    def act(self):
        current_room = self.environment.currentRoom  # Get the current room the agent is in
        all_rooms = self.environment.rooms  # Get all rooms in the environment
        total_rooms = len(all_rooms)  # Count the total number of rooms

        # If the current room is dirty, clean it
        if current_room.status == 'dirty':
            return 'clean'

        current_index = all_rooms.index(current_room)  # Get the index of the current room
        next_index = (current_index + 1) % total_rooms  # Calculate the index of the next room in a cyclic manner

        # If the agent is at the last room, move to the first room
        if current_index == total_rooms - 1:
            return 'left'
        # If not at the last room, move to the next room
        elif next_index == current_index + 1:
            return 'right'
        else:
            return 'left'  # Default to moving left if conditions are not met
