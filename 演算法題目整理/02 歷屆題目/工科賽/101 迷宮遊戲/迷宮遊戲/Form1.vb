Public Class Form1
    Dim map(9, 9), road(64, 2)
    Dim ip As Integer = 1
    Dim che As Boolean = False
    Private Sub TextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TextBox1.TextChanged


    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim fna, s
        OpenFileDialog1.ShowDialog()
        fna = OpenFileDialog1.FileName
        FileOpen(1, fna, OpenMode.Input)
        For i = 0 To 9
            map(i, 0) = 1 : map(0, i) = 1 : map(9, i) = 1 : map(i, 9) = 1
        Next
        For i = 1 To 8
            For j = 1 To 8
                Input(1, map(i, j))
            Next
        Next
        For i = Len(fna) - 1 To 0 Step -1
            If fna(i) = "\" Then
                s = i
                Exit For
            End If
        Next
        fna = Mid(fna, s + 2, Len(fna) - s)
        TextBox1.Text = fna
        Call fin(1, 1)

    End Sub
    Sub fin(ByVal a As Integer, ByVal b As Integer)
        If a = 8 And b = 8 And che = False Then
            Dim w
            For i = 1 To ip - 1
                w = w & "(" & road(i, 1) - 1 & "," & road(i, 2) - 1 & ")"
                If i <> ip - 1 Then
                    w = w & ","
                End If
            Next
            TextBox2.Text = w
            che = True
            Exit Sub
        Else
            If map(a - 1, b) = 0 Then
                road(ip, 1) = a - 1 : road(ip, 2) = b
                ip += 1
                map(a, b) = 1
                fin(a - 1, b)
                map(a, b) = 0
            End If
            If map(a - 1, b + 1) = 0 Then
                road(ip, 1) = a - 1 : road(ip, 2) = b + 1
                ip += 1
                map(a, b) = 1
                fin(a - 1, b + 1)
                map(a, b) = 0
            End If
            If map(a, b + 1) = 0 Then
                road(ip, 1) = a : road(ip, 2) = b + 1
                ip += 1
                map(a, b) = 1
                fin(a, b + 1)
                map(a, b) = 0
            End If
            If map(a + 1, b + 1) = 0 Then
                road(ip, 1) = a + 1 : road(ip, 2) = b + 1
                ip += 1
                map(a, b) = 1
                fin(a + 1, b + 1)
                map(a, b) = 0
            End If
            If map(a + 1, b) = 0 Then
                road(ip, 1) = a + 1 : road(ip, 2) = b
                ip += 1
                map(a, b) = 1
                fin(a + 1, b)
                map(a, b) = 0
            End If
            If map(a + 1, b - 1) = 0 Then
                road(ip, 1) = a + 1 : road(ip, 2) = b - 1
                ip += 1
                map(a, b) = 1
                fin(a + 1, b - 1)
                map(a, b) = 0
            End If
            If map(a, b - 1) = 0 Then
                road(ip, 1) = a : road(ip, 2) = b - 1
                ip += 1
                map(a, b) = 1
                fin(a, b - 1)
                map(a, b) = 0
            End If
            If map(a - 1, b - 1) = 0 Then
                road(ip, 1) = a - 1 : road(ip, 2) = b - 1
                ip += 1
                map(a, b) = 1
                fin(a - 1, b - 1)
                map(a, b) = 0
            End If
            map(a, b) = 1
        End If
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub
End Class
