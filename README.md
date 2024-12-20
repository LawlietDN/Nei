**CLI Task Tracker Made With C++ As A Solution For https://roadmap.sh/projects/task-tracker**

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/LawlietDN/Nei.git
   cd Nei
   ```

2. Compile:

    ```bash
    g++  -I src -I src/CLI -I src/CLI/Utility -I src/CLI/Command-Validation -I src/Task\ Management -I src/JSON -I src/Task src/main.cpp src/CLI/cli.cpp src/CLI/Utility/utility.cpp src/Task\ Management/taskManager.cpp src/CLI/Command-Validation/cmdValidator.cpp src/JSON/json.cpp -o nei
    sudo mv nei /usr/local/bin/
    ```

3. Running:

    ```bash
    nei add "Homework assignment to do" -desc "At 10PM"
    nei delete 0.
    nei --help for a detailed explanation of each command.
    ```