with open("data.txt","r") as f:
    data = f.readlines()
    for line in data:
        name, code_val = line.split("#")
        val = code_val.split()[1].strip()
        val = val.removeprefix("(").removesuffix(")").split(",")
        print("{\""+name.strip("\t")+"\",{"+val[0]+","+val[1]+","+val[2]+"}},")