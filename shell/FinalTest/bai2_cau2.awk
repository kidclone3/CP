# BEGIN{print "Tên_sinh_viên\tĐiểm_trung_bình\tKết_quả_thi"; dem=0}
# {
#     avg = ($3 + $4)/2
#     # if (avg >= 5.0) {
#     #     kq = "Đỗ"
#     # }
#     # else {
#     #     kq = "Trượt"
#     # }
#     # print $1 "\t" avg "\t" kq
#     if ($2 == "Nu" && avg > 8.0) {
#         print $1
#         dem += 1
#     }
# }
# END{if (dem == 0) print "Không có sinh viên thỏa mãn yêu cầu lọc"}
BEGIN{ans=""; mx=0}
{
    if ($3 > mx) {
        mx = $3
        ans = $1
    }
    else if ($3 == mx) {
        ans = ans "\n" $1
    }
}
END{print ans}