// import express from "express";
// import cors from "cors";

// const app = express();
// app.use(cors({ origin: "*", methods: ["POST", "GET", "DELETE", "PUT"] }));
// app.use(express.json());

// let projects = [
//   { id: 1, name: "Todo List" },
//   { id: 2, name: "Weather App" },
// ];

// // Get total number of projects
// app.get("/api/projects/count", (req, res) => {
//   res.json({ count: projects.length });
// });

// // Get all projects
// app.get("/api/projects", (req, res) => {
//   res.json(projects);
// });

// // Add a new project
// app.post("/api/projects", (req, res) => {
//   const { name } = req.body;

//   if (!name || name.length < 3) {
//     return res.status(400).json({ message: "Project name must be at least 3 characters" });
//   }

//   if (projects.some(p => p.name.toLowerCase() === name.toLowerCase())) {
//     return res.status(400).json({ message: "Project name already exists" });
//   }

//   const newProject = { id: projects.length + 1, name };
//   projects.push(newProject);
//   res.status(201).json(newProject);
// });

// // Update project name
// app.put("/api/projects/:id", (req, res) => {
//   const projectId = parseInt(req.params.id);
//   const { name } = req.body;

//   const project = projects.find(p => p.id === projectId);
//   if (!project) {
//     return res.status(404).json({ message: "Project not found" });
//   }

//   if (!name || name.length < 3) {
//     return res.status(400).json({ message: "Project name must be at least 3 characters" });
//   }

//   if (projects.some(p => p.id !== projectId && p.name.toLowerCase() === name.toLowerCase())) {
//     return res.status(400).json({ message: "Project name already exists" });
//   }

//   project.name = name;
//   res.json({ message: "Project updated", project });
// });

// // Delete project
// app.delete("/api/projects/:id", (req, res) => {
//   const projectId = parseInt(req.params.id);
//   const projectIndex = projects.findIndex(p => p.id === projectId);

//   if (projectIndex === -1) {
//     return res.status(404).json({ message: "Project not found" });
//   }

//   const deletedProject = projects.splice(projectIndex, 1)[0];
//   res.json({ message: "Project deleted", deletedProject });
// });

// // Start server
// const PORT = 5000;
// app.listen(PORT, () => console.log(`Server running on port ${PORT}`));









const express = require("express");
const cors = require("cors");
const mongoose = require("mongoose");
require("dotenv").config();
const stripe = require("stripe")(process.env.PRIVATE_SECRET_KEY);

const app = express();
const PORT = 8080;

app.use(express.json({ limit: "10mb" }));
app.use(cors({
    origin: "http://localhost:5173",
    methods: ["GET", "POST"],
    credentials: true
}));

//mongoDB Connection
mongoose.connect('mongodb://localhost:27017/E-com');

const UserSchema = new mongoose.Schema({
    firstName: String,
    lastName: String,
    email: String,
    password: String,
    confirmPassword: String
});

const userModel = mongoose.model('users', UserSchema);
// API
app.get('/', (req, res) => {

});


//SIGNUP API
app.post("/signup", async (req, res) => {
    const { email } = req.body;
    const existingUser = await userModel.findOne({ email });
    if (existingUser) {
        return res.send({ message: "Email already exists", alert: false });
    }
    else {
        const data = new userModel(req.body);
        const result = await data.save();
        res.send({ message: "Successful Registration!", alert: true });
    }
});

//LOGIN API
app.post("/login", async (req, res) => {
    const { email } = req.body;
    const existingUser = await userModel.findOne({ email });
    console.log(req.body);
    const userData = {
        firstName: existingUser.firstName,
        lastName: existingUser.lastName,
        email: existingUser.email,
        password: existingUser.password,
        confirmPassword: existingUser.confirmPassword
    }
    if (!existingUser) {
        return res.send({ message: "Email is not registered, please Signup!", alert: false });
    }
    else {
        res.send({ message: " logged in successfully!", alert: true, data: userData });
    }
});


// products Schema
const productSchema = new mongoose.Schema({
    name: String,
    image: String,
    price: String,
    description: String,
    category: String
});

const productModel = mongoose.model('productdetails', productSchema);

// to add newproducts
app.post('/newproducts', async (req, res) => {
    const data = new productModel(req.body);
    const result = await data.save();
    res.send({ message: "Successful!" })
});

// to get all the products
app.get('/products', async (req, res) => {
    const data = await productModel.find({})
    res.send(JSON.stringify(data));
})

// checkout
app.post('/create-checkout', async (req, res) => {
    const { products } = req.body;
    const lineItems = products.map((product) => ({
        price_data: {
            currency: "usd",
            product_data: {
                name: product.name,
                // images: [product.image]
            },
            unit_amount: Math.round(product.price * 282.69) // Fixed syntax error
        },
        quantity: product.qty 
    }));

    const session = await stripe.checkout.sessions.create({
        payment_method_types: ["card"],
        line_items: lineItems,
        mode: "payment",
        success_url: "http://localhost:5173/",
        cancel_url: "http://localhost:5173/cart"
    });

    res.json({ id: session.id });

});


app.listen(PORT);