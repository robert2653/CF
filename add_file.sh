#!/bin/bash
source="init.cpp"
read -p "要生幾題: " N

# Ensure the Contest directory exists
rm -rf Contest
mkdir -p Contest

# Initialize the ASCII value for 'A'
A=65

for ((i = 0; i < N; i++)); do
    # Calculate the current character
    current_char=$(printf "\\$(printf '%03o' $((A + i)))")

    # Generate the filename (A.cpp, B.cpp, etc.)
    filename="Contest/p${current_char}.cpp"
    # Copy the init.cpp to the new filename
    cp "$source" "$filename"
done

cp "$source" "test.cpp"

echo "Done"