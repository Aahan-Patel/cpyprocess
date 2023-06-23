import cpyprocess

def execute_win(cmd:str) -> str: 
    return cpyprocess.execute(cmd)

print(execute_win("dir"))