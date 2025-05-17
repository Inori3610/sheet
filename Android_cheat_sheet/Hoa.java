package com.example.qlhoa;

public class Hoa {

    String Mahoa,Tenhoa,Maloaihoa;
    int soluong,dongia;
    String anh;

    public Hoa(String mahoa, String tenhoa, String maloaihoa, int soluong, int dongia, String anh) {
        Mahoa = mahoa;
        Tenhoa = tenhoa;
        Maloaihoa = maloaihoa;
        this.soluong = soluong;
        this.dongia = dongia;
        this.anh = anh;
    }

    public String getMahoa() {
        return Mahoa;
    }

    public void setMahoa(String mahoa) {
        Mahoa = mahoa;
    }

    public String getTenhoa() {
        return Tenhoa;
    }

    public void setTenhoa(String tenhoa) {
        Tenhoa = tenhoa;
    }

    public String getMaloaihoa() {
        return Maloaihoa;
    }

    public void setMaloaihoa(String maloaihoa) {
        Maloaihoa = maloaihoa;
    }

    public int getSoluong() {
        return soluong;
    }

    public void setSoluong(int soluong) {
        this.soluong = soluong;
    }

    public int getDongia() {
        return dongia;
    }

    public void setDongia(int dongia) {
        this.dongia = dongia;
    }

    public String getAnh() {
        return anh;
    }

    public void setAnh(String anh) {
        this.anh = anh;
    }
}
