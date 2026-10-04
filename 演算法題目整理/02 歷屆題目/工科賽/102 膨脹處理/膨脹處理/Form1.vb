Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim OFD As New OpenFileDialog
        OFD.ShowDialog()
        Dim bmp = New Bitmap(OFD.FileName)
        PictureBox1.Image = bmp
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim bmp As Bitmap = PictureBox1.Image
        Dim n(bmp.Size.Width - 1, bmp.Size.Height - 1) As Color
        Dim vist(bmp.Size.Width - 1, bmp.Size.Height - 1) As Boolean
        For i = 0 To bmp.Size.Width - 1
            For j = 0 To bmp.Size.Height - 1
                Dim r As Integer = bmp.GetPixel(i, j).R
                Dim g As Integer = bmp.GetPixel(i, j).G
                Dim b As Integer = bmp.GetPixel(i, j).B
                If (r + g + b) / 3 <> 0 And vist(i, j) = False Then
                    n(i, j) = bmp.GetPixel(i, j)
                ElseIf (r + g + b) = 0 Then
                    If i <> 0 And j <> 0 And i <> bmp.Size.Width - 1 And j <> bmp.Size.Height - 1 Then
                        n(i + 1, j + 1) = Color.Black
                        n(i, j + 1) = Color.Black
                        n(i + 1, j) = Color.Black
                        n(i - 1, j - 1) = Color.Black
                        n(i - 1, j) = Color.Black
                        n(i, j - 1) = Color.Black
                        n(i, j) = Color.Black
                        vist(i + 1, j + 1) = True
                        vist(i, j + 1) = True
                        vist(i + 1, j) = True
                        vist(i - 1, j - 1) = True
                        vist(i - 1, j) = True
                        vist(i, j - 1) = True
                        vist(i, j) = True
                    End If
                End If
            Next
        Next
        For i = 0 To bmp.Size.Width - 1
            For j = 0 To bmp.Size.Height - 1
                bmp.SetPixel(i, j, n(i, j))
            Next
        Next
        PictureBox1.Image = bmp
    End Sub
End Class
