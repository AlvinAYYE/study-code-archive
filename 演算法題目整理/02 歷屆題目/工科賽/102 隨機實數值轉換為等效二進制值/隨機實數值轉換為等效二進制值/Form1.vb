Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim a
        a = Rnd()
        a = Fix(a * (10 ^ 10))
        a /= 10 ^ 6
        TextBox1.Text = a
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim a As Double
        Dim b, c
        Dim r, k, x, k2
        Dim g As Boolean = False
        a = TextBox1.Text
        b = Fix(a)
        c = a - b
        While b <> 0
            r = (b Mod 2) & r
            b = Fix(b / 2)
        End While
        For i = 1 To 10
            c *= 2
            x = Fix(c)
            k = k & x
            c -= x
            If c = 0 Then
                Exit For
            End If
        Next
        TextBox2.Text = r & "." & k
        For i = Len(k) - 1 To 0 Step -1
            If k(i) = "1" Then
                k2 = k(i) & k2
                g = True
            ElseIf g = True Then
                k2 = k(i) & k2
            End If
        Next
        TextBox3.Text = r & "." & k2
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        End
    End Sub
End Class
