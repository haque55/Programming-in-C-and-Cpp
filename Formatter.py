import os

def formatter(filePath):
    print('Working on ' + filePath)
    with open(filePath, 'r+') as file:
        data = file.read()
        pos = data.find('*/', 0, len(data))
        print('*/ is found at ' + str(pos))
    os.remove(filePath)
    with open(filePath, 'w+') as formatted:
        formatted.write(data[pos + 3:])

def getListOfFiles(directoryName):
    localFileList = os.listdir(directoryName)
    files = []

    for object in localFileList:
        objectPath = os.path.join(directoryName, object)
        if os.path.isdir(objectPath):
            files += getListOfFiles(objectPath)
        else:
            if object.endswith(".c") or object.endswith(".cpp") or object.endswith(".h"):
                files.append(objectPath)
                
    return files
        
if __name__ == '__main__':
    directoryName = "./files"

    fileList = getListOfFiles(directoryName)
    
    for file in fileList:
        print(file)
        formatter(file)