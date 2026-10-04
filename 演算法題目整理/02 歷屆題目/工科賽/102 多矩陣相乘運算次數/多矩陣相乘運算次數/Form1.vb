Public Class Form1
    Dim k(10), g(10, 2)
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim Data(10, 2), s, ans
        For i = 1 To Val(TextBox1.Text)
            Data(i, 1) = Val(g(i, 1).Text) : Data(i, 2) = Val(g(i, 2).Text)
        Next
        Dim ntv(Val(TextBox1.Text))
        For i = 1 To Val(TextBox1.Text)
            ntv(i) = i
        Next
        For i = 1 To Val(TextBox1.Text)
            For j = i + 1 To Val(TextBox1.Text)
                If Data(ntv(i), 2) < Data(ntv(j), 2) Then
                    s = ntv(i)
                    ntv(i) = ntv(j)
                    ntv(j) = s
                End If
            Next
        Next
        For i = 1 To Val(TextBox1.Text)
            If ntv(i) <> 0 Then
                For j = Val(TextBox1.Text) To 1 Step -1

                Next
            End If
        Next
    End Sub
    Private Sub TextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TextBox1.TextChanged
        k(1) = m1 : k(2) = m2 : k(3) = m3 : k(4) = m4 : k(5) = m5 : k(6) = m6 : k(7) = m7 : k(8) = m8 : k(9) = m9 : k(10) = m10
        g(1, 1) = m11 : g(1, 2) = m12 : g(2, 1) = m21 : g(2, 2) = m22 : g(3, 1) = m31 : g(3, 2) = m32 : g(4, 1) = m41 : g(4, 2) = m42 : g(5, 1) = m51 : g(5, 2) = m52 : g(6, 1) = m61 : g(6, 2) = m62 : g(7, 1) = m71 : g(7, 2) = m72 : g(8, 1) = m81 : g(8, 2) = m82 : g(9, 1) = m91 : g(9, 2) = m92 : g(10, 1) = m101 : g(10, 2) = m102
        If Val(TextBox1.Text) <= 20 Then
            Label2.Text = "請輸入m1~m" & TextBox1.Text & "的矩陣大小(維度)："
            For i = 1 To Val(TextBox1.Text)
                k(i).visible = True
                g(i, 1).visible = True : g(i, 2).visible = True
            Next
            For i = Val(TextBox1.Text) + 1 To 10
                k(i).visible = False
                g(i, 1).visible = False : g(i, 2).visible = False
            Next
            Label3.Location = New Point(24, 85 + (Val(TextBox1.Text) * 25))
            Label3.Visible = False
        End If
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub
End Class
