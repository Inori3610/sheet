package com.example.login_listview;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.ArrayList;
import java.util.List;

public class MainActivity2 extends AppCompatActivity {
    EditText edt_masv,edt_hoten,edt_lop;
    Button btn_them,btn_sua,btn_xoa,btn_thoat;
    ListView lvsv;
    svadapter adapter;
    List<SinhVien> listSV;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main2);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        //link
        linking();

        setListSV();     // Set gia tri cho list_view
        setAdapter();    // Set adapter


        btn_them.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(getApplicationContext(),"Nut them",Toast.LENGTH_LONG).show();
                if (!edt_masv.getText().toString().isEmpty()&&!edt_hoten.getText().toString().isEmpty()&&!edt_lop.getText().toString().isEmpty()){
                    String masv = edt_masv.getText().toString();
                    String hoten = edt_hoten.getText().toString();
                    String lop = edt_lop.getText().toString();
                    SinhVien sv = new SinhVien(masv,hoten,lop);
                    listSV.add(sv);
                }
                setAdapter();
            }
        });
        btn_sua.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(getApplicationContext(),"Nut sua",Toast.LENGTH_LONG).show();
            }
        });

        btn_xoa.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(getApplicationContext(),"Nut xoa",Toast.LENGTH_LONG).show();
            }
        });

        btn_thoat.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(getApplicationContext(),"Nut thoat",Toast.LENGTH_LONG).show();
                Intent intent1 = new Intent(MainActivity2.this,MainActivity.class);
                startActivity(intent1);
            }
        });

    }
    void linking(){
        edt_masv=findViewById(R.id.edt_masv);
        edt_hoten=findViewById(R.id.edt_hoten);
        edt_lop=findViewById(R.id.edt_lop);
        btn_them=findViewById(R.id.btn_them);
        btn_sua=findViewById(R.id.btn_sua);
        btn_xoa=findViewById(R.id.btn_xoa);
        btn_thoat=findViewById(R.id.btn_thoat);
        lvsv=findViewById(R.id.lv);
    }
    private void setListSV(){
        if (listSV==null){
            listSV=new ArrayList<SinhVien>();
            listSV.add(new SinhVien("SV01","Nguyen Hoang Nhat Minh","CNTT"));
        } else {
            adapter.notifyDataSetChanged();
        }
    }
    private void setAdapter(){
        if (adapter==null){
            adapter=new svadapter(MainActivity2.this,R.layout.item_list,listSV);
            lvsv.setAdapter(adapter);
        }else {
            adapter.notifyDataSetChanged();
        }
        // set o text trong
        edt_masv.setText("");
        edt_hoten.setText("");
        edt_lop.setText("");

    }
}