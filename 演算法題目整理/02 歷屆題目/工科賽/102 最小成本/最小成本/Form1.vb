Public Class Form1
    Dim map(7, 7), Data(720)
    Dim ip As Integer = 1
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim fna, a, b, c, w, anst
        Dim All(720)
        OpenFileDialog1.ShowDialog()
        fna = OpenFileDialog1.FileName
        FileOpen(1, fna, OpenMode.Input)
        While Not EOF(1)
            Input(1, a) : Input(1, b) : Input(1, c)
            map(a, b) = c
            w = w & a & "      " & b & "      " & c & vbNewLine
        End While
        TextBox1.Text = w
        Call s1(1)
        For i = 1 To ip - 1
            Dim x, y
            x = 1
            For j = 1 To Len(Data(i))
                If j > 1 Then
                    x = Mid(Data(i), j - 1, 1)
                End If
                y = Mid(Data(i), j, 1)
                x = Val(x) : y = Val(y)
                All(i) += map(x, y)
            Next
        Next
        Dim max As Integer = All(1)
        Dim ans As Integer = 1
        For i = 1 To ip - 1
            If All(i) < max Then
                ans = i
                max = All(i)
            End If
        Next
        anst = anst & "最低成本值總額:" & All(ans) & vbNewLine
        anst = anst & "路徑次序:1 "
        For i = 1 To Len(Data(ans))
            anst = anst & Mid(Data(ans), i, 1) & " "
        Next
        anst = anst & vbNewLine
        anst = anst & "連線數值:" & "0 " & map(1, Val(Mid(Data(ans), 1, 1))) & " "
        For i = 1 To Len(Data(ans)) - 1
            anst = anst & map(Val(Mid(Data(ans), i, 1)), Val(Mid(Data(ans), i + 1, 1))) & " "
        Next
        TextBox2.Text = anst
    End Sub
    Private Sub s1(ByVal a As Integer)
        Dim g, p
        If a = 7 Then
            ip += 1
        Else
            Dim k As Integer = 1
            For i = 1 To 7
                If map(a, i) <> 0 Then
                    If k = 1 Or a = 1 Then
                        Data(ip) = Data(ip) & i
                        s1(i)
                        p = i
                        k += 1
                    Else
                        Dim s
                        s = Str(p)
                        s = Mid(s, 2, 2)
                        g = InStr(Data(ip - 1), s)
                        Data(ip) = Mid(Data(ip - 1), 1, g - 1) & i
                        s1(i)
                    End If
                End If
            Next
        End If
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub
End Class
