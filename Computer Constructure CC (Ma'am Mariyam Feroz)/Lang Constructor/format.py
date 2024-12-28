import json
import os
from Syntax_Analyzer import ast 

syntax_analyzer_output = ast

# Write the JSON output to a file
with open('output.json', 'w') as json_file:
    json.dump(syntax_analyzer_output, json_file, indent=4)  # Format the JSON with indent

print("JSON file created: output.json")

# Open the JSON file after writing it
os.startfile('output.json')  # 'startfile' command for Windows
