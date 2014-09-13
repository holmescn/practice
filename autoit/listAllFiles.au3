#include <Array.au3>
; List all files in the given folder recursively.

Main()

Func Main()
	Local $files[512]
	ListFile($files, "C:\Users\Conan\Desktop\¼æÖ°\Work3\pack\lobby(ÄÚÍø)\xqfanfanqi")
	_ArrayDisplay($files)
EndFunc

Func ListFile(ByRef $result, $root)
	Local $dirs[512]
	Local $search, $file, $dir
	Local $dirIdx = 0, $resultIdx = $result[0], $dirCnt
	; MsgBox(4096, "Dir", $root)
	$search = FileFindFirstFile($root & "\*")
	While 1
		$file = FileFindNextFile($search)
		If @error Then ExitLoop
		If @extended = 1 Then
			; MsgBox(4096, "Dir", $file)
			$dirs[$dirCnt] = $root & "\" & $file
			$dirCnt = $dirCnt + 1
		Else
			; MsgBox(4096, "File", $file)
			$resultIdx = $resultIdx + 1
			$result[$resultIdx] = $root & "\" & $file
		Endif
	Wend
	$result[0] = $resultIdx
	For $dirIdx = 0 To $dirCnt - 1
		ListFile($result, $dirs[$dirIdx])
	Next
EndFunc
