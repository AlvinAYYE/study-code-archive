Public Class Form1
    Private Class tree
        Public root
        Public main()
        Public Lv
        Public Sub Ref()
            ReDim main(2 ^ Lv - 1)
            main(1) = root
        End Sub
        Public Function Add(ByVal a As tree, ByVal b As tree)
            Dim c As tree = New tree
            c.Lv = Math.Max(a.Lv, b.Lv) + 1
            c.root = a.root + b.root
            c.Ref()
            Dim k = 0
            For i = 1 To UBound(a.main)
                If two(i) <> -1 Then
                    k = 2 ^ (two(i) + 1)
                    c.main(k) = a.main(i)
                Else
                    k += 1
                    c.main(k) = a.main(i)
                End If
            Next
            For i = 1 To UBound(b.main)
                If two(i) <> -1 Then
                    k = 2 ^ (two(i) + 1) + (2 ^ (two(i)))
                    c.main(k) = b.main(i)
                Else
                    k += 1
                    c.main(k) = b.main(i)
                End If
            Next
            Return c
        End Function
        Public Function two(ByVal k As Integer)
            For i = 0 To 100
                If k = (2 ^ i) Then
                    Return i
                End If
            Next
            Return -1
        End Function
        Public Function chs(ByVal k As Integer)
            If k * 2 > UBound(main) Then
                main(k) = -1
                Return True
            ElseIf main(k * 2) = Nothing And main(k * 2 + 1) = Nothing Then
                main(k) = -1
                Return True
            End If
            Return False
        End Function
    End Class
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim data = TextBox1.Text
        Dim r = count(data)
        Dim ts(UBound(r, 2)) As tree
        For i = 1 To UBound(ts)
            ts(i) = New tree
            ts(i).Lv = 1 : ts(i).root = r(2, i) : ts(i).Ref()
        Next
        While check(ts)
            Dim m1 = 1000 : Dim m2 = 1000
            Dim p1, p2 As Integer
            For i = 1 To UBound(ts)
                If Not (ts(i) Is Nothing) Then
                    If ts(i).root < m1 Then
                        m1 = ts(i).root
                        p1 = i
                    ElseIf ts(i).root = m1 Then
                        If ts(i).Lv > ts(p1).Lv Then
                            m1 = ts(i).root
                            p1 = i
                        End If
                    End If
                End If
            Next
            For i = 1 To UBound(ts)
                If Not (ts(i) Is Nothing) Then
                    If ts(i).root < m2 And i <> p1 Then
                        m2 = ts(i).root
                        p2 = i
                    ElseIf ts(i).root = m1 And i <> p1 Then
                        If ts(i).Lv > ts(p2).Lv Then
                            m2 = ts(i).root
                            p2 = i
                        End If
                    End If
                End If
            Next
            ts(p1) = ts(p1).Add(ts(p1), ts(p2))
            ts(p2) = Nothing
        End While
        Dim hoff As tree = New tree
        For i = 1 To UBound(ts)
            If Not (ts(i) Is Nothing) Then
                hoff = ts(i)
            End If
        Next
        For i = 1 To UBound(r, 2)
            For j = 1 To UBound(hoff.main)
                If hoff.main(j) = r(2, i) Then
                    If hoff.chs(j) Then
                        r(2, i) = countcode(j)
                        Exit For
                    End If
                End If
            Next
        Next
        Dim w = ""
        For i = 1 To UBound(r, 2)
            w = w & r(1, i) & " : " & r(2, i) & vbNewLine
        Next
        R1.Text = w
        Dim ans = ""
        For i = 0 To Len(data) - 1
            For j = 1 To UBound(r, 2)
                If r(1, j) = data(i) Then
                    ans = ans & r(2, j)
                End If
            Next
        Next
        T2.Text = ans
    End Sub
    Private Function count(ByVal s As String)
        Dim ans(2, 0), ip : ip = 0
        For i = 0 To Len(s) - 1
            Dim k = s(i)
            Dim o As Boolean = False
            For j = 1 To ip
                If k = ans(1, j) Then
                    o = True
                    ans(2, j) += 1
                End If
            Next
            If o = False Then
                ip += 1
                ReDim Preserve ans(2, ip)
                ans(1, ip) = k
                ans(2, ip) = 1
            End If
        Next
        Return ans
    End Function
    Private Function check(ByVal a() As tree)
        Dim o = 0
        For i = 1 To UBound(a)
            If Not (a(i) Is Nothing) Then
                o += 1
            End If
        Next
        If o = 1 Then
            Return False
        Else
            Return True
        End If
    End Function
    Private Function countcode(ByVal k As Integer)
        Dim w = ""
        While k <> 1
            If k Mod 2 = 0 Then
                w = "0" & w
                k /= 2
            Else
                w = "1" & w
                k = Fix(k / 2)
            End If
        End While
        Return w
    End Function

    Private Sub RichTextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles R1.TextChanged

    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub
End Class
