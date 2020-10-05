<script>
    import { onMount } from 'svelte';
    import { beforeUpdate, afterUpdate } from 'svelte';

    import {withLineNumbers} from './lib/linenumbers.js';
    import {CodeJar} from './lib/codejar.js'

    export let id;
    let jar;
    let editor
    export let lang;
    
    const highlight = editor => {
        editor.textContent = editor.textContent
        hljs.highlightBlock(editor)
    }
    onMount(() => {
        hljs.initHighlightingOnLoad();
        jar = CodeJar(editor,withLineNumbers(highlight),{tab: "  "})         
    
    });
    afterUpdate(() => {
        if (editor)highlight(editor);
    });
    $: {
        console.log("language: ",lang)
    }

    let fileReader = new FileReader();
    fileReader.addEventListener('load', (event) => {
        console.log(event.currentTarget.result)
        jar.updateCode(event.currentTarget.result)
    });

    function dropHandler(ev) {
        console.log('File(s) dropped');
        // Prevent default behavior (Prevent file from being opened)
        ev.preventDefault();
            if (ev.dataTransfer.items) {
                if (ev.dataTransfer.items[0].kind === 'file') {
                        var file = ev.dataTransfer.items[0].getAsFile();
                        fileReader.readAsText(file)
                        download(file)
                }
            }
        }
    function dragOverHandler(ev) {
        console.log('File(s) in drop zone'); 

        // Prevent default behavior (Prevent file from being opened)
        ev.preventDefault();
    }
    let download = (file) => {
        let link = document.createElement('a');
        link.download = 'a.cpp';
        link.href = window.URL.createObjectURL(file);
        link.click();
    }




</script>

<div id= {id} bind:this = {editor} class="editor lang-{lang}" on:drop={dropHandler} on:dragover={dragOverHandler} >
const hello = "world-{id[6]}";
/*Drop File Here*/
</div >

<style>
    .editor {
        border-radius: 6px;
        box-shadow: 0 2px 2px 0 rgba(0, 0, 0, 0.14), 0 1px 5px 0 rgba(0, 0, 0, 0.12), 0 3px 1px -2px rgba(0, 0, 0, 0.2); 
        font-family: 'Source Code Pro', monospace;
        font-size: 14px;
        font-weight: 400;
        height: 340px;
        text-align: left;
        letter-spacing: normal;
        line-height: 20px;
        padding: 10px; 
        tab-size: 4;
    }
</style>