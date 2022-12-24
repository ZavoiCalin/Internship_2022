import random
import argparse
import sys
import subprocess



def process_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--min', type=int, required=True)
    parser.add_argument('--max', type=int, required=True)

    return parser.parse_args()

args = process_args()
min = args.min
max = args.max

answer = random.randint(min, max)

def process_choice(c):
    if(int(c) == 1):
        sys.exit()
    else:
        subprocess.run(['python3', str(sys.argv[0]), '--min', str(min), '--max', str(max)])







score = max/2

no_guesses = 0

hints = ["The parity of the answer: ", "Your guess is ", "Divisible by "]

if __name__ == "__main__":

    
    

    while(score > 0):
        guess_s = input("Guess: \n")

        guess = int(guess_s)
        no_guesses += 1

        if (guess != answer):

            score -= no_guesses * 2
            i = random.randint(0, 2)
            hint = hints[i]
            final_hint = hint

            if(i == 0):
                if(answer % 2):
                    print(final_hint + "Odd")
                else:
                    print(final_hint + "Even")
        
            if(i == 1):
                if(guess < answer):
                    print(final_hint + "smaller than the answer")
                else:
                    print(final_hint + "bigger than the answer")

            if(i == 2):
                
                div = 2

                while(div <= answer/2):
                    div+=1
                    if(answer % div == 0):
                        final_hint = hint + str(div)
                        print(final_hint)
                        break
                    

                if(div == answer/2):
                    final_hint = "itself (prime number)"
                    print(final_hint)

        else: 
            print("You won! Score: " + str(score))
            choice = input("Choose 1 to exit and 2 to restart: ")
            process_choice(choice)
            break

    print("You lost! " +"The answer was " + str(answer))
    choice = input("Choose 1 to exit and 2 to restart: ")
    process_choice(choice)
