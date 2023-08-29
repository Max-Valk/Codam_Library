#!/bin/bash

# Function to run the philosopher simulation and capture output
run_philosophers() {
    ./philo $1 $2 $3 $4 $5 2>&1
}

echo "Philosophers Program Testing"
echo "--------------------------"

# Check if the correct number of command-line arguments is provided
if [ "$#" -ne 5 ]; then
    echo "Usage: $0 <num_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <num_times_to_eat>"
    exit 1
fi

num_philosophers=$1
time_to_die=$2
time_to_eat=$3
time_to_sleep=$4
num_times_to_eat=$5

# Get user input for loop count
read -p "Enter the number of times to run the test loop: " loop_count

# Run the test loop
for ((i = 1; i <= loop_count; i++)); do
    echo "Test Loop $i"
    echo "----------------"

    # Run the philosopher simulation and capture output
    output=$(run_philosophers $num_philosophers $time_to_die $time_to_eat $time_to_sleep $num_times_to_eat)

    # Display output after philosopher's death statement
    echo "Output after philosopher's death:"
    echo "$output" | sed -n '/died/,$p'

    echo "----------------"
done

echo "Testing complete."
