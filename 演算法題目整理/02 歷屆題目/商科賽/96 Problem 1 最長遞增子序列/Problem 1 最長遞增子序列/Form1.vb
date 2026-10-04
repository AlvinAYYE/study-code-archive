Public Class Form1

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        FileOpen(1, "test1.txt", OpenMode.Input)
        FileOpen(2, "result1.txt", OpenMode.Output)
        Dim a, R(100), w, g
        a = 1
        While a <> 0
            Input(1, a)
            If a = 0 Then
                Exit While
            End If
            Dim ans = 0
            For i = 1 To a
                Input(1, R(i))
            Next
            g = 1
            While g <= a - 1
                If R(g + 1) - R(g) < 0 Then
                    If R(g + 1) - R(g - 1) > 0 Then
                        ans += 1
                        For j = g To a - 1
                            R(j) = R(j + 1)
                        Next
                        g -= 1
                        a -= 1
                    Else
                        ans += 1
                        For j = g + 1 To a - 1
                            R(j) = R(j + 1)
                        Next
                        g -= 1
                        a -= 1
                    End If
                End If
                g += 1
            End While
            w = w & ans & vbNewLine
        End While
        Print(2, w)
    End Sub
End Class
