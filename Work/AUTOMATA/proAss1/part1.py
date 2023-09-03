import argparse
import pytest
import json


def construct(file_str: str) -> dict[str, dict[str, float]]:
    """Takes in the string representing the file and returns pfsa

    The given example is for the statement "A cat"
    """

    file_str = file_str.lower()
    words = file_str.split()
    # print (words)
    
    new_dict = {}
    
    if "*" not in new_dict:
        new_dict["*"] = {}
    
    if file_str == "*":
        return new_dict

    for word in words:

        x = len(word)
        # checking if the first character is connected to "*"

        if word[0] not in new_dict["*"]:
            new_dict["*"][word[0]] = 1
        else:
            new_dict["*"][word[0]] += 1

        tempchar = " "
     
        for i in range (0,x-1):
            tempchar += word[i]
            nextchar = tempchar + word[i+1]
            #  checking if the tempchar is now availaible in the new_dict

            if tempchar not in new_dict:
                new_dict[tempchar]={}
            if nextchar not in new_dict[tempchar]:
                new_dict[tempchar][nextchar] = 1
            else:
                new_dict[tempchar][nextchar] += 1

        if tempchar+word[-1] not in new_dict:
            new_dict[tempchar+word[-1]] = {}
            new_dict[tempchar+word[-1]][tempchar+word[-1] + "*"] = 1

    for key in new_dict:
        totalofkey = 0
        for value in new_dict[key]:
            totalofkey += new_dict[key][value]
        
        for value in new_dict[key]:
            new_dict[key][value] = (new_dict[key][value] / totalofkey)
    
    return new_dict


def main():
    """
    The command for running is `python pfsa.py text.txt`. This will generate
    a file `text.json` which you will be using for generation.
    """
    parser = argparse.ArgumentParser()
    parser.add_argument("file", type=str, help="Name of the text file")
    args = parser.parse_args()

    with open(args.file, "r") as file:
        contents = file.read()
        output = construct(contents)

    name = args.file.split(".")[0]

    with open(f"{name}.json", "w") as file:
        json.dump(output, file)


if __name__ == "__main__":
    main()


STRINGS = ["A cat", "A CAT", "", "A", "A A A A"]
DICTIONARIES = [
    {
        "*": {"a": 0.5, "c": 0.5},
        "a": {"a*": 1.0},
        "c": {"ca": 1.0},
        "ca": {"cat": 1.0},
        "cat": {"cat*": 1.0},
    },
    {
        "*": {"a": 0.5, "c": 0.5},
        "a": {"a*": 1.0},
        "c": {"ca": 1.0},
        "ca": {"cat": 1.0},
        "cat": {"cat*": 1.0},
    },
    {
        "*": {},
    },
    {
        "*": {"a": 1.0},
        "a": {"a*": 1.0},
    },
    {
        "*": {"a": 1.0},
        "a": {"a*": 1.0},
    },
]


@pytest.mark.parametrize("string, pfsa", list(zip(STRINGS, DICTIONARIES)))
def test_output_match(string, pfsa):
    """
    To test, install `pytest` beforehand in your Python environment.

    Run `pytest pfsa.py` Your code must pass all tests. There are additional
    hidden tests that your code will be tested on during VIVA.
    """
    result = construct(string)
    assert result == pfsa