import win32clipboard
import win32con

INPUT_FILE_PATH = 'inputFile.txt'
OUT_FILE_PATH = 'outputFile.txt'

def changeEnterChar(inputStr):
    return inputStr.replace('\r\n', ' ').replace('\n', ' ')

def getCopyText():
    win32clipboard.OpenClipboard()
    copy_text = win32clipboard.GetClipboardData(win32con.CF_TEXT)
    win32clipboard.CloseClipboard()
    return copy_text

def setCopyText(textStr):
    win32clipboard.OpenClipboard()
    win32clipboard.EmptyClipboard()
    win32clipboard.SetClipboardText(textStr)
    win32clipboard.CloseClipboard()

if __name__ == '__main__':
    inputStr = getCopyText()
    outStr = changeEnterChar(inputStr)
    setCopyText(outStr)
    with open(OUT_FILE_PATH, 'w') as outFile:
        outFile.write(outStr)
