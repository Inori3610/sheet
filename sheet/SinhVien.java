package com.example.login_listview;

public class SinhVien {
    //Khai bao cac thuoc tinh
    private String masv,hoten,lop;
    // right click : Generate ＞︿＜
    // + Constructor(rong) Constructor(variable)
    // + Get Set
    // + toString()
    public SinhVien() {
    }

    public SinhVien(String masv, String hoten, String lop) {
        this.masv = masv;
        this.hoten = hoten;
        this.lop = lop;
    }

    public String getHoten() {
        return hoten;
    }

    public void setHoten(String hoten) {
        this.hoten = hoten;
    }

    public String getLop() {
        return lop;
    }

    public void setLop(String lop) {
        this.lop = lop;
    }

    public String getMasv() {
        return masv;
    }

    public void setMasv(String masv) {
        this.masv = masv;
    }

    @Override
    public String toString() {
        return "SinhVien{" +
                "masv='" + masv + '\'' +
                ", hoten='" + hoten + '\'' +
                ", lop='" + lop + '\'' +
                '}';
    }
}
