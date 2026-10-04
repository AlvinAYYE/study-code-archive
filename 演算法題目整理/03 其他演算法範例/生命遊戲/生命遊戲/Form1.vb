Public Class Form1
    Dim map(40, 40) As Np
    Private Class Np
        Inherits PictureBox
        Public bmp As Bitmap
        Public Alive As Boolean
        Protected Overrides Sub OnClick(ByVal e As System.EventArgs)
            If Alive = False Then
                Alive = True
                MyClass.Image = bmp
            Else
                Alive = False
                MyClass.Image = Nothing
            End If
        End Sub
    End Class
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        For i = 1 To 40
            For j = 1 To 40
                map(i, j) = New Np
                map(i, j).Width = 16 : map(i, j).Height = 16
                map(i, j).Top = (j - 1) * 15
                map(i, j).Left = (i - 1) * 15
                map(i, j).BorderStyle = BorderStyle.FixedSingle
                map(i, j).bmp = IL1.Images(0)
                map(i, j).Alive = False
                Me.Controls.Add(map(i, j))
            Next
        Next
        For i = 0 To 40
            map(i, 0) = New Np
            map(i, 0).Alive = False
            map(0, i) = New Np
            map(0, i).Alive = False
        Next
    End Sub
    Function count(ByVal x As Integer, ByVal y As Integer)
        Dim ans = 0
        If map(x - 1, y).Alive = True Then
            ans += 1
        End If
        If map(x - 1, y - 1).Alive = True Then
            ans += 1
        End If
        If map(x, y - 1).Alive = True Then
            ans += 1
        End If
        If x < 40 Then
            If map(x + 1, y).Alive = True Then
                ans += 1
            End If
            If map(x + 1, y - 1).Alive = True Then
                ans += 1
            End If
        End If
        If y < 40 Then
            If map(x, y + 1).Alive = True Then
                ans += 1
            End If
            If map(x - 1, y + 1).Alive = True Then
                ans += 1
            End If
        End If
        If x < 40 And y < 40 Then
            If map(x + 1, y + 1).Alive = True Then
                ans += 1
            End If
        End If
        Return ans
    End Function
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Timer1.Start()
    End Sub
    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Dim Nmap(40, 40) As Np
        Nmap = map
        For i = 1 To 40
            For j = 1 To 40
                Select Case count(i, j)
                    Case 0, 1
                        Nmap(i, j).Alive = False
                    Case 3
                        Nmap(i, j).Alive = True
                    Case Is >= 4
                        Nmap(i, j).Alive = False
                End Select
            Next
        Next
        map = Nmap
        Call press()
    End Sub
    Private Sub press()
        Dim o As Integer = 0
        For i = 1 To 40
            For j = 1 To 40
                If map(i, j).Alive Then
                    map(i, j).Image = map(i, j).bmp
                    o += 1
                Else
                    map(i, j).Image = Nothing
                End If
            Next
        Next
        L1.Text = o
    End Sub
    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Timer1.Stop()
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Dim Nmap(40, 40) As Np
        Nmap = map
        For i = 1 To 40
            For j = 1 To 40
                Select Case count(i, j)
                    Case 0, 1
                        Nmap(i, j).Alive = False
                    Case 3
                        Nmap(i, j).Alive = True
                    Case Is >= 4
                        Nmap(i, j).Alive = False
                End Select
            Next
        Next
        map = Nmap
        Call press()
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Dim n = InputBox("n=?")
        For s As Integer = 1 To Val(n)
            Dim Nmap(40, 40) As Np
            Nmap = map
            For i = 1 To 40
                For j = 1 To 40
                    Select Case count(i, j)
                        Case 0, 1
                            Nmap(i, j).Alive = False
                        Case 3
                            Nmap(i, j).Alive = True
                        Case Is >= 4
                            Nmap(i, j).Alive = False
                    End Select
                Next
            Next
            map = Nmap
        Next
        Call press()
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        Timer1.Stop()
        For i = 1 To 40
            For j = 1 To 40
                map(i, j).Image = Nothing
                map(i, j).Alive = False
            Next
        Next
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        End
    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        Timer1.Enabled = Not Timer1.Enabled
        For i = 1 To 40
            For j = 1 To 40
                map(i, j).Image = map(i, j).bmp
            Next
        Next
        Timer1.Enabled = Not Timer1.Enabled
    End Sub
End Class
