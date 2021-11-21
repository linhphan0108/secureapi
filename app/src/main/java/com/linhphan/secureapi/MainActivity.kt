package com.linhphan.secureapi

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import com.linhphan.secureapi.databinding.ActivityMainBinding
import java.util.ArrayList

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = APIKeyLibrary.getAppId()
        val objects = APIKeyLibrary.getSSLCerts()
        if (objects is ArrayList<*>){
            objects.forEach {
                if (it is android.util.Pair<*, *>){
                    Log.i("MainActivity", "domain = ${it.first} - cert = ${it.second}")
                }
            }
        }
    }
}